//--lower_bound------
//bool C()�������𔻒肷��֐�

//�ŏ��l������������
//lb�������𖞂����Ȃ��l�ɁCub�������𖞂����l�ɏ��������C���̑��ݔ͈͂��\���������Ȃ�܂ŌJ��Ԃ�
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

//�ő�l������������
//lb�������𖞂����l�ɁCub�������𖞂����Ȃ��l�ɏ��������C���̑��ݔ͈͂��\���������Ȃ�܂ŌJ��Ԃ�
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
