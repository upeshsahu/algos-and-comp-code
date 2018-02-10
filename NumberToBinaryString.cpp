string convertToBinary(int num){

	string str="";

	if(num==0)
		str="0";

	while(num){

		int b=num%2;

		if(b==1)
			str.append("1");
		else
			str.append("0");
      
		num=num/2;
	}

	reverse(str.begin(),str.end());
  
  int n=str.size();

	int rem=sizeof(num)*8-n;  

	for(int i=0;i<rem;++i){

		str="0"+str;

	}
  
	return str;

}
