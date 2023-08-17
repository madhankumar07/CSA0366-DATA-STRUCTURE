#include <stdio.h>
void findDuplicates(int arr[], int n)
{
  int temp[n];
  int count = 0; 
  for(int i=0; i<n; i++) {   
    int element = arr[i];
    int flag = 0;  
    for(int j=0; j<count; j++) {
      if(temp[j] == element) {
        flag = 1;
        break;
      }
    }   
    if(flag) {
      continue;
    }
    for(int j=i+1; j<n; j++) {
      if(arr[j] == element) {
        temp[count++] = element;
        break;
      }
    }
  }
  printf("Repeated elements are: ");
  for (int i = 0; i < count; i++) {
    printf("%d ",temp[i]);
  }
}
int main()
{
  int arr[] = {50, 20, 10, 40, 20, 10, 10, 60, 30, 70};
  int size = sizeof(arr)/sizeof(arr[0]);
  findDuplicates(arr, size);
  return 0;
}
