#ifndef Commands_HPP
#define Commands_HPP

#include <Server.hpp>
#include <DefineMod.hpp>
#include <Error.hpp>

typedef int (*fp_command)(const vector<string> &input, User& user);


namespace cmd
{
	int join(const vector<string> &input, User& user);
	int nick(const vector<string> &input, User& user);
	int quit(const vector<string> &input, User& user);
	int kill(const vector<string> &input, User& user);
	int ping(const vector<string> &input, User& user);
	int pong(const vector<string> &input, User& user);
	int	who(const  vector<string> &input, User& user);
	int	user(const vector<string> &input, User& user);
	int	pass(const vector<string> &input, User& user);
	int	part(const vector<string> &input, User& user);
	int privmsg(const vector<string> &input, User& user);
	int list(const vector<string> &input, User &user);
}

bool isEqual(const string &test, const string &aim, int enter);
void write_fd(int fd, const string &msg);



#endif
