#include <sys/inotify.h>

int main() {
	inotify_add_watch(fd, "example.c", mask);
	/*
	 * IN_ACCESS 
	 * IN_ATTRIB
	 * IN_CLOSE_WRITE
	 * IN_CLOSE_NOWRITE
	 * IN_CREATE
	 * IN_DELETE
	 * IN_DELETE_SELF
	 * IN_MODIFY
	 * IN_MOVE_SELF
	 * IN_MOVED_FROM
	 * IN_MOVED_TO
	 * IN_OPEN
	 *
	 * ***********************************
	 * IN_ALL_EVENTs
	 * IN_MOVE
	 * IN_CLOSE
	 * ***********************************
	 * IN_DONT_FOLLOW
	 * IN_MASK_ADD
	 * IN_ONESHOT
	 * IN_ONLYDIR
	 * IN_IGNORED
	 * IN_ISDIR
	 * IN_Q_OVERFLOW
	 * IN_UNMOUNT
	 * ***********************************
	 */
}


struct inotify_event {
	int wd;
	uint32_t mask;
	uint32_t cookie;
	uint32_t len;
	char names[];
};


