#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include<numeric>
using namespace std;

bool sortbysec(const pair<double,double> &a,
              const pair<double,double> &b)
{
    return (a.second < b.second);
}
int main()
{
cout<<"Enter Number of process"<<endl;
vector<pair<double,double>> v;
vector<pair<double,double>> v_sorted;
int no_p ; cin>>no_p;
double input1,input2;
cout<<"Enter Arrival Time and Brust Time for each process"<<endl;
for(int i = 0;i<no_p;i++){
    cin>>input1>>input2;
    v.push_back(make_pair(input1,input2));}
  int minElementIndex = std::min_element(v.begin(),v.end()) - v.begin();
  v_sorted.push_back(make_pair(v[minElementIndex].first,v[minElementIndex].second));
  v.erase(v.begin()+minElementIndex);
  sort(v.begin(), v.end(), sortbysec);
  v.insert(v.begin(),v_sorted[0]);
   double wt [no_p+1];
    wt[0]={0};
    double sum =0;
    for(int i=1;i<no_p;i++){
    for (int j=i ; j>0;j--){
        sum+=v[(j-1)].second;
    }
         wt[i]=sum-v[i].first;
         sum=0;
    }
    double total =0;
    for(int i =0;i<no_p;i++){
        total+=wt[i];

    }
cout << "Processes "<<"Arrival Time"<< " Burst time "
		<< " Waiting time \n";


	for (int i=0; i<no_p; i++)
	{
		cout << " " << i+1 << "\t\t" << v[i].first<<"\t "<<v[i].second<<"\t \t "
			<< wt[i] <<"\t\t "<<endl;
	}

    double avg_wt = total/no_p;
    cout<<"Average Waiting Time  "<<avg_wt;


    return 0;}
