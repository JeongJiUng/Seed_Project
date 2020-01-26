#pragma once

namespace lev
{
constexpr auto				SUCC = 1;
constexpr auto				FAIL = 0;

constexpr auto				MAX_QUEUE_LENGTH = 500;

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
#include <random>
#include <ctime>

#include <sys/ioctl.h>
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
#include "lev_random.h"
#include "lev_tick.h"
#include "lev_crypt.h"

#include "lev_mutex_lock.h"
#include "lev_multi_thread_sync.h"
#include "lev_thread.h"

#include "lev_circular_queue.h"

#include "lev_memory_pool.h"

#include "lev_stream.h"

#include "lev_receive.h"
#include "lev_send.h"

#include "lev_server_option.h"

#include "lev_endpoint.h"
#include "lev_socket.h"
#include "lev_epoll.h"
#include "lev_server.h"

#include "lev_heart_beat.h"

#include "lev_server_adaptor.h"

#include "lev_client.h"
#include "lev_client_manager.h"