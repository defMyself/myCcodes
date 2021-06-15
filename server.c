int main(int argc, char* argv[]) {
	int fd1, fd2, fd3;
	fd1 = open(argv[1], O_RDONLY);
	fd2 = open(argv[2], O_RDONLY);
	fd3 = open(argv[3], O_RDONLY);

	printf("server: %d \n", getpid());

	fd_set readset, bak_set;
	FD_ZERO(&bak_set);
	FD_SET(fd1, &bak_set);

	struct timeval = tm;
	tm.tv_sec = 10;
	tm.tv_usec = 0;

	sleep(10);
}