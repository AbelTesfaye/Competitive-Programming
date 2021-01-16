// Complete the bonAppetit function below.
void bonAppetit(vector<int> bill, int k, int b) {
    int sum = 0;
    for(int i: bill){
        sum += i;
    }
    sum -= bill[k];
    sum /= 2;
    
    if(b == sum){
        cout<<"Bon Appetit";
    } else {
        cout<<b - sum;
    }

}