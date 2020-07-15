# numbers-to-texts
In this code,we can converts numbers into texts.

```
 numberstotexts.cpp
```
# Test Cases

INPUT | OUTPUT 

  17  Rs.Seventeen ONLY 
  25  Rs.Twenty Five ONLY 
#include <iostream> 
#include <cmath>
using namespace std; 

// strings at index 0 is not used, it is to make array 
// indexing simple 
string one[] = { "", "one ", "two ", "three ", "four ", 
				"five ", "six ", "seven ", "eight ", 
				"nine ", "ten ", "eleven ", "twelve ", 
				"thirteen ", "fourteen ", "fifteen ", 
				"sixteen ", "seventeen ", "eighteen ", 
				"nineteen " }; 

// strings at index 0 and 1 are not used, they is to 
// make array indexing simple 
string ten[] = { "", "", "twenty ", "thirty ", "forty ", 
				"fifty ", "sixty ", "seventy ", "eighty ", 
				"ninety " }; 

// n is 1- or 2-digit number 
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

// Function to print a given number in words 
string convertToWords(long n) 
{ 
	// stores word representation of given number n 
	string out; 

	// handles digits at ten millions and hundred 
	// millions places (if any) 
	out += numToWords((n / 10000000), "crore "); 

	// handles digits at hundred thousands and one 
	// millions places (if any) 
	out += numToWords(((n / 100000) % 100), "lakh "); 

	// handles digits at thousands and tens thousands 
	// places (if any) 
	out += numToWords(((n / 1000) % 100), "thousand "); 

	// handles digit at hundreds places (if any) 
	out += numToWords(((n / 100) % 10), "hundred "); 

	if (n > 100 && n % 100) 
		out += "and "; 

	// handles digits at ones and tens places (if any) 
	out += numToWords((n % 100), ""); 

	return out; 
} 

// Driver code 
int main() 
{ 
    double f;
	cout << "Enter the currency value:";
	cin >> f;
	//double fiiii=13234254.743;
    
    if(f<0 or f>=999999.99){
        cout << "please enter the value below 999999.99";
    }
    else{
	    long int_part = (int)f;
	    double fractional = round(f*100)/100 - int_part;
	    int fractional_part_in_integer = (int)(fractional*100);
	    //printf("%d, %d\n ", int_part, fractional_part_in_integer);
	    // convert given number in words 
	    cout << convertToWords(int_part) << fractional_part_in_integer << "/100 only" << endl; 
    }
	return 0; 
} 
