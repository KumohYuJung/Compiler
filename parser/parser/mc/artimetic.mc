/*
artimatic
모든 수열의 값들이 0보다 큰 등차수열
*/
void main(){
	int list[100];
	int start, d, n;
	read(start);	
	read(d);
	read(n);
	list = arti(start, d, n);
	print(list);
}
// start, d, n 파라미터 입력 받고, 결과값으로 등차수열 반환
int[] arti(int start, int d, int n){
	int list[100];
	int i;
	i = 1;
	while(start < n){
		list[i] = start;
		++i;
		start = start + d;
	}
	list[i] = -1;
	return list;
}
// 배열을 입력받아 합을 반환
void print(int[] list){
	int i;
	i = 1;
	while(list[i] != -1){
		write(list[i]);
		++i;
	}
}
