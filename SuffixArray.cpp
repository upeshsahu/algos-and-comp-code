/* Code for suffix array creation using n*(logn^2) complexity */

int sa[100005],pos[100005],tmp[100005],N,gap;

bool sufCmp(int i,int j){

    if(pos[i]!=pos[j])
    	return pos[i]<pos[j];

    i+=gap;
    j+=gap;

    return (i<N && j<N)? pos[i]<pos[j]:i>j;

}

void buildSA(string str){

    N=str.size(); 

    for(int i=0;i<N;++i){
    	sa[i]=i;
        pos[i]=str[i];

    } 	

    /* Gap is the length of m-gram in each step,divided by 2
       We start with 2-grams,so gap is 1 initially,It then increases to 2,4,8 and so on. */

    for(gap=1;;gap*=2){
 
        /* We sort by (gap*2)-grams */
        sort(sa,sa+N,sufCmp);

        /* We compute the lexicographic rank
        of each m-gram we have sorted above */

        for(int i=0;i<N-1;++i){

        	 tmp[i+1]=tmp[i]+sufCmp(sa[i],sa[i+1]);
        }

        /* tmp contains the rank by position.Now we map 
        into pos,so that in next step we can look
        up per m-gram rather than by position. */

        for(int i=0;i<N;++i)
        	 pos[sa[i]]=tmp[i];

        if(tmp[N-1]==N-1) break;	

    }


}
