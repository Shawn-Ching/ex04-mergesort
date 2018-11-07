//
// Created by Shawn Ching on 9/26/18.
//

#ifndef EX04_MERGESORT_MERGESORT_H
#define EX04_MERGESORT_MERGESORT_H

#include <cstdint>
#include <cstdlib>

namespace edu { namespace vcccd { namespace vc { namespace csv15 {

                template <class T>
                void merge(T array[], T temp[], size_t left, size_t mid, size_t rightEnd)
                {
                    size_t leftEnd = mid - 1;
                    size_t tempIndex = left;   ///temp array index
                    size_t tempSize = (rightEnd - left + 1);

                    while (left <= leftEnd && mid <= rightEnd)   ///compare left & right and write in the lesser of the two into temp array
                    {
                        if (array[left] < array[mid])
                        {
                            temp[tempIndex] = array[left];
                            left++;
                        }
                        else
                        {
                            temp[tempIndex] = array[mid];
                            mid++;
                        }
                        tempIndex++;
                    }
                    while  (left <= leftEnd)   ///write in the rest of left if right is empty
                    {
                        temp[tempIndex] = array[left];
                        tempIndex++;
                        left++;
                    }
                    while (mid <= rightEnd)   ///write in the rest of right if left is empty
                    {
                        temp[tempIndex] = array [mid];
                        tempIndex++;
                        mid++;
                    }
                    for (int i = 0; i < tempSize; i++)  ///writing temp array back to original array
                    {
                        array[rightEnd] = temp[rightEnd];
                        rightEnd--;
                    }
                }

                template <class T>
                void myMerge(T array[], T temp[], size_t start, size_t finish)
                {
                    if (finish > start)
                    {
                        size_t mid = (start + finish) / 2;
                        myMerge(array, temp, start, mid);
                        myMerge(array, temp, (mid+1), finish);

                        merge(array, temp, start, (mid+1), finish);
                    }

                }
                template <class T>
                void mergesort(T array[], size_t size)
                {
                    size_t tempSize = size;
                    T temp[tempSize];
                    myMerge(array, temp, 0, size-1);
                }
            }}}}

#endif //EX04_MERGESORT_MERGESORT_H
