void main()
{
	int i;
	for(i = 0 ; i < 20; i++)
	{
		switch(i)
		{
			case 1: case 3: case 5: case 7:
				write(1);
			case 2: case 4: case 6: case 8:
				write(2);
			case 0: 
				write(0);
			default:
				write(3);
		}
	}
}
