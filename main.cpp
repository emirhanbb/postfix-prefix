#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool operand(char c) {
	if(c >= '0' && c <= '9') 
    return true;
   	 return false;
}


bool operat(char c) {
	if((c == '+') || (c == '-')||(c == '/' )|| (c == '*')||(c=='^')) 
    return true;
   	 return false;
}

string postfix(string ifade){
	stack<string> a; 
	
	for(int i=0;i<ifade.length();i++){
		if(operand(ifade[i])){
			string donusum(1,ifade[i]);
			a.push(donusum);
		}
	
		else{
			string operator1 =a.top();
			a.pop();
			string operator2 = a.top();
			a.pop();
			a.push("(" + operator2 + ifade[i] + 
				operator1 + ")"); 
		}
	}
	
	return a.top();
}



string prefix(string ifade){
	

	stack<string> b; 
	
	for(int i=0;i<=ifade.length();i++){
		if(operat(ifade[ifade.length()-i])){
				string operator1 =b.top();
				b.pop();
				string operator2 = b.top();
				b.pop();
				b.push("(" + operator1 + ifade[ifade.length()-i] + 
				operator2+ ")"); 
			
		}
	
		else{
		string donusum(1,ifade[ifade.length()-i]);
			b.push(donusum);
		}
	}
	
	return b.top();
}
	


int main(int argc, char** argv) {
cout<<"Postfix: 23*45*+6-"; 
string a = "23*45*+6-";
cout<<"	Infix:";
cout<<postfix(a)<<endl;

cout<<"Postfix: 78+925--34+^"; cout<<"	Infix:"; 
string b = "78+925--34+^";
cout<<	postfix(b)<<endl;

cout<<"Postfix: 456*+7-"; cout<<"	Infix:"; 
string c = "456*+7-";
cout<<	postfix(c);	

cout<<endl<<"-------------------------------------"<<endl;
cout<<"Prefix: -*+24-58+73"; cout<<"		Infix:"; 
string d = "-*+24-58+73";
cout<<prefix(d)<<endl;

cout<<"Prefix: -+*23*549"; cout<<"		Infix:"; 
string f = "-+*23*549";
cout<<prefix(f)<<endl;	

cout<<"Prefix: ++3*579"; cout<<"			Infix:"; 
string e = "++3*579";
cout<<prefix(e)<<endl;	

	
	return 0;
}
