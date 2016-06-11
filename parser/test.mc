void main(){
	int i,j;
	i = 3;
	switch (i)
	{
		case 1: case 2:
			write(i);
			break;
		case 3:	
			break;
	}
	for(j = 0,i = 2; j < 3 && i < 4; j++)
	{
		write(i);
	}
}


