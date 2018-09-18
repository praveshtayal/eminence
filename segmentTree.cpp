#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

template<typename T>
class segmentTree {
  public:
    segmentTree(vector<T>& _v) {
      size = pow(2, log2(_v.size()))-1;

      // Update Segment Tree
      tree = vector<int>(2*size+1, 0);
      copy(_v.begin(), _v.end(), tree.begin()+size);
      for(int i = size-1; i>=0; i--) tree[i] = tree[i*2+1] + tree[i*2+2];

      // Update leftI and rightI Tree
      leftI = vector<int>(2*size+1, 0);
      rightI = vector<int>(2*size+1, 0);
      updateIndex(0, 0, size);
    }
    void updateIndex(int index, int left, int right) {
      if(index>2*size) return;
      leftI[index] = left;
      rightI[index] = right;
      int half = (right-left)/2;
      updateIndex(index*2+1, left, left+half);
      updateIndex(index*2+2, left+half+1, right);
    }
    void update(int index, T& value) {
      int i= size+index;
      tree[i] = value;
      i = (i-1)/2;
      for(i = (i-1)/2; i>=0; i = (i-1)/2) tree[i] = tree[i*2+1] + tree[i*2+2]; 
    }
    int query(int index, int left, int right) {
      if(leftI[index]==left && rightI[index]==right) return tree[index];
      int ans = 0;
      int leftChild = 2*index + 1;
      int rightChild = 2*index + 2;
      if(rightI[leftChild]>=leftI[index]) ans += query(leftChild, left, right);

    }
    int query(int left, int right) {
      return query(0, left, right);
    }
    void print() const {
      cout << size << endl;
      copy(tree.begin(), tree.end(), ostream_iterator<int>(cout, " ")); cout << endl;
      copy(leftI.begin(), leftI.end(), ostream_iterator<int>(cout, " ")); cout << endl;
      copy(rightI.begin(), rightI.end(), ostream_iterator<int>(cout, " ")); cout << endl;
    }
  private:
    vector<T> v, tree;
    vector<int> leftI, rightI;
    int size;
    int log2(int n) { return ceil(log(n) / log(2)); }
};

int main()
{
  int arr1[] = {10, 20, 30, 40 };
  int arr2[] = {10, 20, 30, 40, 50, 60, 70 };
  vector<int> v1 (arr1, arr1+(sizeof(arr1)/sizeof(int)));
  vector<int> v2 (arr2, arr2+(sizeof(arr2)/sizeof(int)));

  segmentTree<int> t1(v1), t2(v2);
  t1.print();
  t2.print();
}

