#include <cstdio>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <iostream>

#ifndef ONLINE_JUDGE
#define DEBUG(X) { X; }
//#define DEBUG_INPUT(X) { X; }
#define DEBUG_INPUT(X) //{ X; }
#else
#define DEBUG(X)
#define DEBUG_INPUT(X)
#endif

using namespace std;

const unsigned MAX_N = 1024;

namespace
{
  // Actual footprint is NUM_BLOCKS multipled by this.
  //const int BLOCK_SIZE_BYTES = 2048;
  //const int BLOCK_SIZE_BYTES = 65536;
  //const int BLOCK_SIZE_BYTES = 4096;

  const int BLOCK_SIZE_BYTES = 128 * 4096;

  //const int BLOCK_SIZE_BYTES = 16;
  //const int BLOCK_SIZE_BYTES = 256;
  //const int BLOCK_SIZE_BYTES = 1024;
  //const int BLOCK_SIZE_BYTES = 128;
  //const int BLOCK_SIZE_BYTES = MAX_N * 4;

  const int NUM_BLOCKS = 2;

  class input
  {
  public:

    explicit input()
      : size_(0), index_(0), current_(0), eof_(false)
    {
#ifdef ONLINE_JUDGE
      std::ios_base::sync_with_stdio(false);
#endif
      read_block();
    }

    inline bool read_int(int &v)
    { 
      bool negative = false;
      v = 0;

      if(size_ > 16)
      {
        while(!isdigit(*current_))
        {
          if(*current_ == '-')
            negative = true;
          advance();
        }
        
        while(isdigit(*current_))
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }
      else
      {
        while(!isdigit(*current_) && !end_reached())
        {
          if(*current_ == '-')
            negative = true;
          advance();
        }
        
        while(isdigit(*current_) && !end_reached())
        {
          v = v * 10 + *current_ - '0';
          advance();
        }
      }

      if(negative) 
        v *= -1;

      DEBUG(printf("size_ = %d v = %d\n", size_, v));

      return !end_reached();
    }

    inline bool end_reached() const
    {
      return // eof_ && 
        size_ == 0;
    }

  private:
    
    inline void advance()
    {
      DEBUG_INPUT(printf("advance (pre) size_ = %d current = [%c]\n", size_, *current_));
      --size_;
      if(size_ == 0)
      {
        //if(!eof_)
          read_block();
      }
      else
      {
        ++current_;
      }
      DEBUG_INPUT(printf("advance (post) size_ = %d current = [%c]\n", size_, *current_));
    }

    inline void read_block()
    {
      current_ = &blocks_[index_][0];
      //size_ = fread(current_, sizeof(char), BLOCK_SIZE_BYTES);
      size_ = read(0, current_, sizeof(char) * BLOCK_SIZE_BYTES);
      //eof_ = (feof(stdin) != 0);
      eof_ = (size_ == 0);
#ifndef ONLINE_JUDGE
      char output[BLOCK_SIZE_BYTES + 1];
      strncpy(output, blocks_[index_], BLOCK_SIZE_BYTES);
      printf("READ BLOCK [%s]\n", output);
#endif
      DEBUG_INPUT(printf("READ BLOCK size = %d eof = %s\n", size_, eof_ ? "yes" : "no"));
      ++index_;
      index_ = index_ % NUM_BLOCKS;
      DEBUG_INPUT(printf("next index = %d\n", index_));
    }

    // Remaining bytes left in current block
    size_t size_;
    size_t index_;
    char *current_;
    char blocks_[NUM_BLOCKS][BLOCK_SIZE_BYTES];
    bool eof_;
  };

} // namespace


int n;
//long long counter;
int values[MAX_N];
int temp_val[MAX_N];

void dump()
{
  for(int i = 0; i < n; ++i)
    printf("values[%d] = %d\n", i, values[i]);
}


// long long  _mergeSort(int arr[], int temp[], int left, int right);
// long long merge(int arr[], int temp[], int left, int mid, int right);
  
/* This function sorts the input array and returns the
   number of inversions in the array */
// inline long long mergeSort(int arr[], int array_size)
// {
//   //int *temp = (int *)malloc(sizeof(int)*array_size);
//     return _mergeSort(arr, temp_val, 0, array_size - 1);
// }
  
// /* An auxiliary recursive function that sorts the input array and
//   returns the number of inversions in the array. */
// long long _mergeSort(int arr[], int temp[], int left, int right)
// {
//   int mid;
//   long long counter = 0;
//   if (right > left)
//   {
//     /* Divide the array into two parts and call _mergeSortAndCountInv()
//        for each of the parts */
//     mid = (right + left)/2;
  
//     /* Inversion count will be sum of inversions in left-part, right-part
//       and number of inversions in merging */
//     if(mid > left)
//       counter  = _mergeSort(arr, temp, left, mid);
//     if(right > mid+1)
//       counter += _mergeSort(arr, temp, mid+1, right);
  
//     /*Merge the two parts*/
//     counter += merge(arr, temp, left, mid+1, right);
//   }
//   return counter;
// }
  
/* This funt merges two sorted arrays and returns inversion count in
   the arrays.*/
inline int merge(int arr[], int temp[], int left, int mid, int right)
{
  int i, j, k;
  int counter = 0;
  
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
      counter = counter + (mid - i);
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
  
  return counter;
}

/* An auxiliary recursive function that sorts the input array and
  returns the number of inversions in the array. */
inline int _mergeSort(int arr[], int temp[], int left, int right)
{
  int mid;
  int counter = 0;
  if (right > left)
  {
    /* Divide the array into two parts and call _mergeSortAndCountInv()
       for each of the parts */
    mid = (right + left)/2;
  
    /* Inversion count will be sum of inversions in left-part, right-part
      and number of inversions in merging */
    if(mid > left)
      counter  = _mergeSort(arr, temp, left, mid);
    if(right > mid+1)
      counter += _mergeSort(arr, temp, mid+1, right);
  
    /*Merge the two parts*/
    counter += merge(arr, temp, left, mid+1, right);
  }
  return counter;
}

inline int mergeSort(int arr[], int array_size)
{
  //int *temp = (int *)malloc(sizeof(int)*array_size);
    return _mergeSort(arr, temp_val, 0, array_size - 1);
}

int main()
{
  input inp;
  while(inp.read_int(n))
  {
    if(n == 0) break;
    DEBUG(printf("N = %d\n", n));
    for(int i = 0; i < n; ++i)
      inp.read_int(values[i]);
    DEBUG(dump());
    const int counter = mergeSort(values, n);
    //DEBUG(dump());
    printf("Minimum exchange operations : %d\n", counter);
  }

  return 0;
}
