
#include <iostream> 
#include <cmath>
using namespace std; 

string one[] = { "", "one ", "two ", "three ", "four ", 
				"five ", "six ", "seven ", "eight ", 
				"nine ", "ten ", "eleven ", "twelve ", 
				"thirteen ", "fourteen ", "fifteen ", 
				"sixteen ", "seventeen ", "eighteen ", 
				"nineteen " }; 

string ten[] = { "", "", "twenty ", "thirty ", "forty ", 
				"fifty ", "sixty ", "seventy ", "eighty ", 
				"ninety " }; 

string numToWords(int n, string s) 
{ 
	string str = ""; 
	// if n is more than 19, divide it 
	if (n > 19) 
		str += ten[n / 10] + one[n % 10]; 
	else
		str += one[n]; 

	// if n is non-zero 
	if (n) 
		str += s; 

	return str; 
} 

string convertToWords(long n) 
{ 
	string out; 

	out += numToWords((n / 10000000), "crore "); 

	out += numToWords(((n / 100000) % 100), "lakh "); 

	out += numToWords(((n / 1000) % 100), "thousand "); 

	out += numToWords(((n / 100) % 10), "hundred "); 

	if (n > 100 && n % 100) 
		out += "and "; 
	
	out += numToWords((n % 100), ""); 

	return out; 
} 

int main() 
{ 
    double f;
	cout << "Enter the currency value:";
	cin >> f;
    
    if(f<0 or f>=999999.99){
        cout << "please enter the value below 999999.99";
    }
    else{
	    long int_part = (int)f;
	    double fractional = round(f*100)/100 - int_part;
	    int fractional_part_in_integer = (int)(fractional*100);
	   
	    cout << convertToWords(int_part) << fractional_part_in_integer << "/100 only" << endl; 
    }
	return 0; 
} 
