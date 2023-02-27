#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
     int arr[25][25]={0};
     cout<<"Enter size(odd):";
     int size;
     cin>>size;
     int i=0,j=(size-1)/2,n=1;
     arr[i][j]=n;
     while(n<=size*size){
           i--;
           j--;
           if(i<0&&j>=0){
                i=size-1;
                arr[i][j]=n;
                n++;
          }else if(j<0&&i>=0){
                j=size-1;
                arr[i][j]=n;
                n++;
          }else if(i<0&&j<0){
                i=i+2;
                j=j+1;
                arr[i][j]=n;
                n++;
          }else if(arr[i][j]!=0){
                i=i+2;
                j=j+1;
                arr[i][j]=n;
                n++;
          }else{  
                arr[i][j]=n;
                n++;
          }
      }
      for(i=0;i<size;i++){  
            for(j=0;j<size;j++){
                  cout<<setw(3)<<arr[i][j];
            }
            cout<<endl;
      }
      return 0;
  }