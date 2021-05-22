//
//  main.cpp
//  les_1102
//
//  Created by пупсик on 11.02.2021.
//  Copyright © 2021 пупсик. All rights reserved.
//

#include <iostream>
using namespace std;

const double PI=3.141593;

double Circles(double R) {
    return PI*R*R;
}

int main() {
    int R;
    for (int i=0; i<3; i++) {
        cin>>R;
        cout<<Circles(R)<<endl;
    }
    return 0;
}




/*
int RootsCount(int a,int b,int c) {
    int d=(b*b)-4*a*c;
    if (d<0)
        return 0;
        else if (d==0)
            return 1;
    return 2;
}

int main() {
    int a, b, c;
    cin>>a>>b>>c;
    
cout<<RootsCount (a, b, c)<<endl;
}
*/
/*
int Sign(double x)
{
    if (x<0)
        return -1;
    else if (x==0)
        return 0;
    return 1;
}


int main(){
    double a, b;
    cin>>a>>b;
    cout<<Sign(a)+Sign(b)<<endl;
    
}

*/

/*
int main() {
    int n=3, s1=0;
    double s2=0;
    double x;
    for (int i=0; i<n; i++) {
        cin>>x;
        s1+=int(x);
        s2+=x-int(x);
    }
    cout<<s1<<endl<<s2<<endl;
}
*/


/*
int main() {
double a, s=0, p=1;
    int n;
    cin>>n;
    for (int i=0; i<n; i++) {
        cin>>a;
        s+=a;
        p*=a;
    }
    cout<<s<<endl<<s/n<<endl<<p<<endl;
  }*/

/*
int main() {
    int n, k=0;
    cin>>n;
    while (n%2==0) {
        k++;
        n/=2;
    }
    cout<<k<<endl;
}
*/






/*
int main() {
    int n, k;
    cin>>n;
    while (n%3==0) {
        n/=3;
    }
    bool z=false;
    
    if (n==1)
        z=true;

    cout<<z<<endl;
}
*/


/*
int main() {
    int a, b, s=0;
    cin>>a>>b;
    while (a>b) {
        a-=b;
        s+=1;
    }
    cout<<s<<endl;
}
*/


/*
int main() {
    int x=239;
    while (x>0) {
        std::cout<<x%3<<std::endl;
        x=x/3;
    }
    return 0;
}*/
/*
int main() {
double p;
cin >> p;
for (double i = 0.1; i <= 1; i = i + 0.1) {
cout << p*i << endl;
}
}
*/
