#pragma once

namespace lev
{
constexpr auto				SUCC = 1;
constexpr auto				FAIL = 0;

constexpr auto				BUFF_SIZE = 64;

constexpr auto				SERVER_OPTION = "/home/leviathan/projects/Leviathan/server_options/server_option.json";

//#define						CURRENT_TIME											cClock::get_instance()->get_time()

enum TRIGGER_MOD
{
	LEVEL_TRIGGER			= 0,
	EDGE_TRIGGER
};
}

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <queue>
#include <pthread.h>
#include <mutex>
#include <stdarg.h>

#include <sys/time.h>
#include <sys/unistd.h>
#include <sys/socket.h>
#include <sys/epoll.h>
#include <arpa/inet.h>
#include <linux/limits.h>
#include <fstream>
#include <execinfo.h>
#include <signal.h>
#include <ucontext.h>

#include <unordered_map>

using namespace	std;
using namespace lev;

#include "include/tcmalloc.h"
#include "include/jsoncpp/json.h"

#include "lev_singleton.h"
#include "lev_json.h"
#include "lev_log.h"

#include "lev_close_socket.h"
#include "lev_server_option.h"

#include "lev_socket.h"
#include "lev_bind.h"
#include "lev_listen.h"
#include "lev_accept.h"
#include "lev_server.h"

#include "lev_epoll.h"
#include "lev_epoll_create.h"
#include "lev_epoll_ctl.h"
#include "lev_epoll_wait.h"
#include "lev_epoll_server.h"

#include "lev_server_adaptor.h"
#include "lev_leviathan_server.h"

#include "lev_client.h"