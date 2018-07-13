#include "headers.h"
vector<int> removeDuplicates(vector<int> input){
  /* Given an integer array A which contains duplicates. Remove duplicates from
   * the array and return a new array without any duplicates. That is, it
   * should contain only unique elements.
   * Best case time complexity-O(n) where n is the no of elements in the array.
   */
  unordered_set<int> s;
  vector<int> result;
  for(vector<int>::iterator it=input.begin(); it!=input.end(); it++)
  {
    // If element already exists, do nothing
    if(s.count(*it)) continue;
    s.insert(*it);
    result.push_back(*it);
  }

  return result;
}

char nonRepeatingCharacter(string str){
  /* In a given string, find the first non-repeating character .You are given
   * a string, that can contain repeating characters. Your task is to return
   * the first character in this string that does not repeat. i.e., occurs
   * exactly once. The string will contain characters only from English
   * alphabet set, i.e., ('A' - 'Z') and ('a' - 'z'). If there is no
   * non-repeating character print the first character of string. */
  unordered_map<char, int> m;
  // Fill the map m with count of each character
  for(string::iterator it=str.begin(); it!=str.end(); it++)
    m[*it]++;

  // Check if map m containts 1 for any char
  for(string::iterator it=str.begin(); it!=str.end(); it++)
    if(m[*it]==1) return *it;
  return str[0];
}

int* stockSpan(int *price, int size) {
  /* The span si of a stock’s price on a certain day i is the minimum number of
   * consecutive days (up to the current day) the price of the stock has been
   * less than its price on that ith day. If for a particular day, if no stock
   * price is greater then just count the number of days till 0th day including
   * current day.*/
  if(price==nullptr || size<=0) return nullptr;
  // stack stores indexes
  stack<int> s;
  int *result = new int[size];
  result[0] = 1;
  s.push(0);
  for(int i=1; i<size; i++)
  {
    result[i] = 1;
    if(price[i-1] >= price[i])
    {
      s.push(i);
      continue;
    }

    if(price[i]>price[s.top()])
    {
      do {
        result[i] += result[s.top()];
        s.pop();
      }while(!s.empty() && price[i]>price[s.top()]);
      s.push(i);
    }
    else
      result[i] += result[i-1];
  }
  return result;
}

vector<int> longestSubsequence(int *arr, int n){
  /* You are given with an array of integers that contain numbers in random
   * order. Write a program to find the longest possible sub sequence of
   * consecutive numbers using the numbers from given array.
   * You need to return the output array which contains consecutive elements.
   * Order of elements in the output is not important. Order(n)
   * If two arrays are of equal length return the array whose index of smallest
   * element comes first. */
  // Stores element and index with element as key
  map<int, int> m;
  for(int i=n-1; i>=0; i--)
    m[arr[i]] = i;
  map<int, int>::iterator it = m.begin();

  // These are values in arr read from smallest element first
  int start, end, maxStart, maxEnd;
  start = end = maxStart = maxEnd = it->first;
  for(it++; it!=m.end(); it++)
  {
    if(it->first==end+1)
    {
      end = it->first;
    }
    else
    {
      // New consecutive subsequence
      // Check if last subsequnce is larger than exiting largest
      if( (end-start > maxEnd-maxStart) ||
       ((end-start == maxEnd-maxStart) && (m[start] < m[maxStart])) )
      {
        // This is longer consecutive subsequence
        maxStart = start;
        maxEnd = end;
      }
      start = end = it->first;
    }
  }
  vector<int> result;
  for(int i=maxStart; i<=maxEnd; i++)
    result.push_back(i);
  return result;
}

char* uniqueChar(char *str){
  /* Given a string, you need to remove all the duplicates. That means, the
   * output string should contain each character only once. The respective
   * order of characters should remain same. */
  if(str==nullptr) return nullptr;
  unordered_set<char> s;
  char *write=str;
  for(char *read=str; *read!='\0'; read++)
  {
    // If element already exists, do nothing
    if(s.count(*read)) continue;
    s.insert(*read);
    *(write++) = *read;
  }
  *write = '\0';

  return str;
}

int kthLargest (vector<int> arr, int n, int k){
  /* Given an array A of random integers and an integer k, find and return the
   * kth largest element in the array in less than O(nlogn) time. */
  // Note that we have size available from vector as well as n
  // priority queue of STL is maxHeap by default. To make it minHeap:
  priority_queue<int, vector<int>, greater<int> > pq;
  k %= n;  // k is smaller than n now
  int i;
  for(i=0; i<k; i++)
    pq.push(arr[i]);
  for(; i<n; i++)
    if(arr[i]>pq.top())
    {
      pq.pop();
      pq.push(arr[i]);
    }
  return pq.top();

}

int main()
{
  // stock span
  int price[]={60, 70, 80, 100, 90, 75, 80, 120};
  int * arr = stockSpan(price, 8);
  for(int i=0; i<8; i++)
    cout << arr[i] << ' ';
  cout << endl;

  int arr2[] = {2,12,9,16,10,5,3,20,25,11,1,8,6};
  vector<int> seq = longestSubsequence(arr2, 13);
  for(int i=0; i<seq.size(); i++)
    cout << seq[i] << ' ';
  cout << endl;
  return 0;
}
