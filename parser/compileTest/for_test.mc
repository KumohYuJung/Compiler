void main()
{
	int i, j, arr[11], temp;
	for(i = 0 ; i < 10; i++)
	{
		read(arr + i);
	}
	for(i = 0; i < 10; i++) {
		for(j = i + 1; j < 10; j++) {
			if(arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		} 
	}
	for(i = 0; i < 10; i++) {
		write(arr[i]);
	}
}