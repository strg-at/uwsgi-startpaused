#include <uwsgi.h>

extern struct uwsgi_server uwsgi;

void pause_workers() {
    int i;
    for (i = 1 - uwsgi.master_process; i < uwsgi.numproc + 1; i++) {
        uwsgi.workers[i].suspended = 1;
    }
}

struct uwsgi_plugin startpaused_plugin = {
    .name = "startpaused",
    .post_fork = pause_workers,
};

