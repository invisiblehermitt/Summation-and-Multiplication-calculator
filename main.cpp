#include<iostream>
#include<string>
#include<vector>
#include<cmath>
using namespace std;

vector<int> changetovec(string num){	//function to change input number to vector;
	
	vector<int> result;

	for(int i=0;i<num.length();i++){

	result.push_back(num[i] - '0');
	
	}

	return result;
}

vector<int> reverse(vector<int> number){	//function to reverse the vector

	vector<int> result;
	int length = number.size();
	for(int i=length-1;i>-1;i--){
		result.push_back(number[i]);
	}
	return result;
}


 vector<int> add(vector<int> num1,vector<int>num2,int B){

	int length1 = num1.size();
	int length2 = num2.size();
	vector<int> value1;
	vector<int> value2;
	vector<int> carry;
	int maxsize;
	int dif;

	if(length1>length2){	//first number is longer
		maxsize=length1+1;
		dif = length1-length2;	//how many digit num1 is more than num2

		for(int i=0;i<dif;i++){
			value2.push_back(0);	//fill in with zeros
		}
		// end with value2

		for(int i=0;i<length2;i++){
			value2.push_back(num2.at(i));	//fill in the value
		}

		//value1.push_back(0);

		for(int i=0;i<length1;i++){
			value1.push_back(num1.at(i));
		}

	}
	else{			//second is longer or they are the same
		maxsize=length2+1;
		dif = length2 - length1;

		if(dif>0){
			for(int i=0;i<dif;i++){
			value1.push_back(0);	//fill in with zeros
		}

		}			

		for(int i=0;i<length1;i++){
			value1.push_back(num1.at(i));	//fill in the value
		}
		//end with value 1
		//value2.push_back(0);

		for(int i=0;i<length2;i++){
			value2.push_back(num2.at(i));
		}

	}
		//value1 = reverse(value1); //it is here cuz value 1 somehow reveresed
	vector<int>sum;
	for(int i=0;i<maxsize;i++){		//set all digits in carry to 0
		carry.push_back(0);		
	}
		//return carry;  evertthing above this doesn't have a segmentation fault.
	//carry[maxsize]=0;
	int temp =value1[maxsize-2] + value2[maxsize-2];	//used to be -1
	if(temp>=B){
		sum.push_back(temp - B);
		carry[maxsize-2]++;
	}

	else{
		sum.push_back(temp);
		
	}
		//return carry; //everything above is correct

	for(int i=maxsize-3;i>-1;i--){

		temp = value1[i] + value2[i] + carry[i+1];
		if(temp>=B){
			sum.push_back(temp - B);
			carry[i]++;
		}
		else{
			sum.push_back(temp);
		}

	}

	if(carry[0]==1){
		sum.push_back(1);
	}

	sum = reverse(sum);
	return sum;	
}

vector<int> singlemulti(vector<int> n1, int n2, int B) {
    int leng = n1.size();
    vector<int> product;
    vector<int> carry;

    for(int i=0;i<leng+1;i++){		//n位数乘1位数结果最高位数为n+1
    	product.push_back(0);	
    	carry.push_back(0);
    }

    for(int i=0;i<leng;i++){
    	product[leng-i] = (n1[leng-i-1] * n2)%B;
    	carry[leng-i-1] = (n1[leng-i-1] * n2)/B;
    }

    vector<int> temp = add(carry,product,B);
    vector<int> result;

    if(temp[0]==0){		//if the first digit has an 0
    	for(int i=1;i<temp.size();i++){
    		result.push_back(temp[i]);
    	}
    }else{
    	result = temp;
    }
    return result;
}

vector<int> mult(vector<int> num1,vector<int> num2, int B ){
	vector<int> p;
	p.push_back(0);
	int leng2 = num2.size();
	vector<int> temp;
	for(int i=0;i<leng2;i++){
		temp = singlemulti(num1,num2[i],B);
		for(int k=0;k<leng2-i-1;k++){
			temp.push_back(0);
		}
		p = add(p,temp,B);
	}

	return p;
}


int main(int argc, char const *argv[])
{
	string num1,num2;
	int Bvalue;
	cin>>num1;
	cin>>num2;
	cin>>Bvalue;

	vector<int>firstnum = changetovec(num1);
	vector<int>secondnum = changetovec(num2);
	vector<int>result = add(firstnum,secondnum,Bvalue);
	vector<int>result1 = mult(firstnum,secondnum,Bvalue);	

	for(int i=0;i<result.size();i++){
		cout<<result.at(i);
	}
		cout<<" ";

	for(int i=0;i<result1.size();i++){
		cout<<result1.at(i);
	}		

	/* code */
	return 0;
}