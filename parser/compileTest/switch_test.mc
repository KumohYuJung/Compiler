void main()
{
	int i;
	for(i = 0 ; i < 20; i++)
	{
		switch(i)
		{
			case 1: case 3: case 5: case 7:
				write(i); lf();write(i+100); lf();
				break;
			case 2: case 4: case 6: case 8:
				write(i);lf();write(i+200);	lf();
				break;
			case 0: 
				write(i);lf();write(i+300);	lf();
				break;
			default:
				write(i);lf();write(i+400);	lf();
				break;
		}
	}
}
