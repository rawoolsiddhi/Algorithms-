#include<iostream>
using namespace std;

struct bag{
    double weight;
    double profit;
};

void accept (struct bag s[], int n );
void sort(struct bag s[], int n);
double fract_knapsack(struct bag s[], int n,int total_weight);


void sort(struct bag s[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            double ratio1 = s[j].profit / s[j].weight;
            double ratio2 = s[j + 1].profit / s[j + 1].weight;

            if (ratio1 > ratio2 || (ratio1 == ratio2 && s[j].weight < s[j + 1].weight)) { // Sort in descending order
                swap(s[j], s[j + 1]);
            }
        }
    }
}

void accept (struct bag s[], int n ){
    for(int i=0; i<n;i++){
         cout << "Item " << i + 1 << " weight: ";
        cin >> s[i].weight;
        cout << "Item " << i + 1 << " profit: ";
        cin >> s[i].profit;
    }
}

double fract_knapsack(struct bag s[], int n,int total_weight){
   
   double current=0;
   double max_profit=0;
    for(int i=0;i<n;i++){
        if(current+s[i].weight<=total_weight){
         current=current+s[i].weight;
         max_profit +=s[i].profit;
        }
        else{
            double remain_weight=total_weight-current;
            max_profit += s[i].profit * (remain_weight / s[i].weight);

            break;
        }
        
    }
    return max_profit;
}

int main(){

    int n, total_weight;
    cout<<"enter the number of items";
    cin>>n;
    struct bag s[n];
    cout<<"weight: ";
    cin>>total_weight;
    accept(s,n);
    sort(s,n);
   double maxProfit = fract_knapsack( s,n, total_weight);

   cout<<"profit is  :"<<maxProfit <<endl;
    return 0;
}
