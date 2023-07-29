#ifndef SERVER_HPP
#define SERVER_HPP

#include "DefineMod.hpp"
#include "Global.hpp"
#include "Response.hpp"

class Server
{
	private:
		int								port;
		string							password;
		map < string, vector<User*> >	channels;
		vector <User*>					users;
	public:
		Server();
		~Server();
		void							toBegin();
		void							handleInput(int fd, const string &input);
		void							setUpSocket();
		const string					getPassword() const;
		vector<User*>					getChannel(const string &channel);
		void							setPort(int port);
		void							setPassword(string pass);
		map< string, vector<User*> >	&getChannels();
		const vector<User*>				getUsers() const;

		/// @brief gets user from list or creates new one and inserts into the list
		/// @param fd 
		/// @return 
		User*	getOrCreateUser(int fd);
		void	deleteUser(int fd);
		void	addUserTo(const string &group, User &user);
		void	removeUserFrom(const string &group, User &user);
		//map<string, string> getChannelList();
};

extern Server start;

#endif