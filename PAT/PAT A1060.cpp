#include<iostream>
#include<string>
using namespace std;

bool divide(string str){
	
	for(string::iterator it=str.begin();it!=str.end();it++){
		if(*it == '.') return true;
	}
	return false;
}

string clear_front_0(string str){

	while(str[0]=='0'&&str.length()>0){
		str.erase(str.begin());
	}
	if(*str.begin()=='.')
		str.insert(0,"0");
	return str;
}

string sci_count(string str,int n){
	str = clear_front_0(str);
	int e = 0,flag = 0;
	string result;
	if(divide(str)){//0.001 12.0001
		int dot = str.find('.');//1 2
		e = str.length()-dot-1;//3 = 5-1-1 4 = 7-2-1
		str = str.erase(str.find('.'),1);
		str = clear_front_0(str);
		// return str;
		cout<<"e of input "<<e<<endl;
		cout<<"str of input"<<str<<endl;
		while(str.length()<n){
			str.insert(str.length(),"0");
			e++;
			flag = 1;
		}
		cout<<"e after add 0 at the end "<<e<<endl;

		string str_1 = str.substr(0,n);
		cout<<"str after selecting n number "<<str_1<<endl;

		if(flag==0){
			// e = -e;
			// e = e+(str.length()-n);
			// e = n-e;
			e = str.length()-e;
			cout<<e<<endl;
		}
		else{
			e = n-e;
			cout<<e<<endl;
		}
		// e = e-n-1;
		// cout<<e<<endl;
		// e=e+n;
		// cout<<e<<endl;
		cout<<"str = 0."<<str_1<<" *10^"<<e<<endl;
		result = "";
		result.insert(result.length(),"0.");
		result.insert(result.length(),str_1);
		result.insert(result.length(),"*10^");
		result.insert(result.length(),to_string(e));
		
		
		return result;
	}
	else{
		while(str.length()<n){
			str.insert(str.length(),"0");
			e++;
			
		}
		string str_1 = str.substr(0,n);
		cout<<"str after selecting n number "<<str_1<<endl;
		e = -e+str.length();
		cout<<"str = 0."<<str_1<<" *10^"<<e<<endl;
		result = "";
		result.insert(result.length(),"0.");
		result.insert(result.length(),str_1);
		result.insert(result.length(),"*10^");
		result.insert(result.length(),to_string(e));
		return result;
	}
	
}

int main(){
	string str1,str2;
	int number;
	cin>>number;
	cin>>str1;
	cin>>str2;
	// cout<<clear_front_0(str1)<<endl;
	// cout<<sci_count(str1,number)<<endl;
	string s1 = sci_count(str1,number);
	string s2 = sci_count(str2,number);
	if(s1==s2){
		cout<<"YES "<<s1<<endl;
	}
	else
		cout<<"NO "<<s1<<" "<<s2<<endl;

}