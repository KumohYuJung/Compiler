void main() {
	int a;
	while (1) {
		read(a);
		if (a < 0) continue;
		else if(a == 0) break;
		else {
			write(a);
			lf();
		}
	}
}