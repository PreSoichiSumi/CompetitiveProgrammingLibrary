//--lower_bound------
//bool C()が条件を判定する関数

//最小値を見つけたい時
//lbを条件を満たさない値に，ubを条件を満たす値に初期化し，解の存在範囲が十分小さくなるまで繰り返す
int nibutan(){
	int lb=-1,ub=n;
	while(ub-lb>1){
	    int mid=(lb+ub)/2;
	    if(C(mid)){
	        ub=mid;
	    }else{
	        lb=mid;
	    }
	}
	return ub;
}

//最大値を見つけたい時
//lbを条件を満たす値に，ubを条件を満たさない値に初期化し，解の存在範囲が十分小さくなるまで繰り返す
int nibutan(){
	int lb=0,ub=INF;
	while(ub-lb>1){
	    int mid=(lb+ub)/2;
	    if(C(mid)){
	        ub=mid;
	    }else{
	        lb=mid;
	    }
	}
	return lb;
}
