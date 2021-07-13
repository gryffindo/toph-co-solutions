#include<bits/stdc++.h>
using namespace std;

int main()
{
    double hour, minute, cell, angle_1, angle_2;

	cin >> hour >> minute;
    angle_1 = (hour*5.0) + (minute/12.0);
    angle_1 *= 6.00;

    angle_2 = (minute*6.00);

    cell = angle_1 - angle_2;

    cell = min(cell, (360-cell));
	
	cout << cell; 

    return 0;
}

// Problem Link: https://toph.co/p/clock-math
