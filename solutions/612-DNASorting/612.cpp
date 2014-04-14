#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>

#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <iterator>
#include <bitset>

#include <unistd.h>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
#else
#define DEBUG(X)
#endif

using namespace std;

const int N_MAX = 64;
const int M_MAX = 128;

char sequence[M_MAX][N_MAX];

const int SCORE_MAX = 2048;

int scores[SCORE_MAX][M_MAX];

char output[M_MAX * N_MAX];

char temp[N_MAX];

int  _mergeSort(char *arr, char *temp, int left, int right);
int merge(char *arr, char *temp, int left, int mid, int right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
int mergeSort(char *arr, int array_size)
{
  //char *temp = (char *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp, 0, array_size - 1);
}
  
/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
int _mergeSort(char *arr, char *temp, int left, int right)
{
  int mid, inv_count = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    inv_count  = _mergeSort(arr, temp, left, mid);
    inv_count += _mergeSort(arr, temp, mid+1, right);
  
    /*Merge the two parts*/
    inv_count += merge(arr, temp, left, mid+1, right);
  }
  return inv_count;
}
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
int merge(char *arr, char *temp, int left, int mid, int right)
{
  int i, j, k;
  int inv_count = 0;
  
  i = left; /* i is index for left subarray*/
  j = mid;  /* i is index for right subarray*/
  k = left; /* i is index for resultant merged subarray*/
  while ((i <= mid - 1) && (j <= right))
  {
    if (arr[i] <= arr[j])
    {
      temp[k++] = arr[i++];
    }
    else
    {
      temp[k++] = arr[j++];
  
     /*this is tricky -- see above explanation/diagram for merge()*/
      inv_count = inv_count + (mid - i);
    }
  }
  
  /* Copy the remaining elements of left subarray
   (if there are any) to temp*/
  while (i <= mid - 1)
    temp[k++] = arr[i++];
  
  /* Copy the remaining elements of right subarray
   (if there are any) to temp*/
  while (j <= right)
    temp[k++] = arr[j++];
  
  /*Copy back the merged elements to original array*/
  for (i=left; i <= right; i++)
    arr[i] = temp[i];
  
  return inv_count;
}
  

// Simple
// int count_inversions(int seq, int n)
// {
//   int inversions = 0;
//   for(int i = 0; i < n; ++i)
//     for(int j = i + 1; j < n; ++j)
//       if(sequence[seq][i] > sequence[seq][j])
//         ++inversions;
//   //  DEBUG(printf("inversions [%s] = %d\n", &sequence[seq][0], inversions));
//   return inversions;
// }

int main()
{
#ifdef ONLINE_JUDGE
  std::ios_base::sync_with_stdio(false);
#endif

  int d;

  if(scanf("%d\n", &d));

  DEBUG(printf("d = %d\n", d));

  for(int t = 0; t < d; ++t)
  {
    int n, m;

    if(scanf("%d %d\n", &n, &m));

    DEBUG(printf("N = %d M = %d\n", n, m));

    for(int i = 0; i < SCORE_MAX; ++i)
      scores[i][0] = 0;

    for(int i = 0; i < m; ++i)
    {
      if(scanf("%s\n", &sequence[i][0]));
      DEBUG(printf("sequence[%d] = [%s]\n", i, &sequence[i][0]));
      //      const int inversions = count_inversions(i, n);
      char buffer[N_MAX];
      memcpy(&buffer[0], &sequence[i][0], n);
      const int inversions = mergeSort(&buffer[0], n);
      DEBUG(printf("inversions [%s] = %d\n", &sequence[i][0], inversions));
      scores[inversions][++scores[inversions][0]] = i;
    }

    int k = 0;

    for(int i = 0; i < SCORE_MAX; ++i)
      if(scores[i][0] > 0)
      {
        for(int j = 1; j <= scores[i][0]; ++j)
        {
          const int index = k * (n+1);
          DEBUG(printf("k = %d index = %d sequence = %d\n", k, index, scores[i][j]));
          memcpy(&output[index], &sequence[scores[i][j]][0], n * sizeof(char));
          output[index + n] = '\n';

          if(++k == m)
            break;
        }
      }

    if(t > 0)
      write(1, "\n", 1);
    write(1, &output[0], (n + 1) * m);
  }
  
  return 0;
}
