/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayadi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 17:30:38 by aayadi            #+#    #+#             */
/*   Updated: 2015/02/24 17:30:40 by aayadi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include "libft.h"
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ncurses.h>
#include <string.h>
#include <unistd.h>

# define UPDATE_NICKNAME "/nick"
# define JOIN_CHANNEL "/join"
# define WHO "/who"
# define MSG "/msg"
# define LEAVE "/leave"
# define DECO "/quit"
# define CO "/connect"

# define LIST "^List"
# define SENDER "sender$"
# define B2C "#B2C"
# define HEC "#HEC"
# define PEDAGO "#PEDAGO"
# define STAFF "#STAFF"
# define PUBLIC "#PUBLIC"


typedef struct		s_ncurse
{
	int 				row;
	int 				col;
	WINDOW				*win_term;
	WINDOW				*win_chat;
	WINDOW				*win_channel;
	WINDOW				*win_member;
}					t_ncurse;

typedef struct		s_irc
{
	int						serv_sock;
	int						cli_sock;
	int 					sockmax;
	char					buff[1024];
	char					*name;
	char					*msg;
	char					*nick_def;
	fd_set					readfds;
		
}					t_irc;

typedef 	struct 	s_lst_member
{
	char				*nickname;
	char				*chanel;
	int 				socket;
	struct s_lst_member	*next;
}						t_lst_member;

typedef 	struct 	s_list_mess
{
	struct 	s_list_mess	*begin;
	struct 	s_list_mess	*end;
	struct 	s_list_mess	*prev;
	struct 	s_list_mess	*next;
	void				*msg;
	int 				length;
}					t_list_mess;

typedef		struct s_info_client
{
	char				*nickname;
	char				*channel;
	int 				socket;
	char				*str;
}					t_info_client;


int				check_cmd_client(char *buff, t_ncurse *curs);
int				check_cmd(char *buff);

int				create_socket(int client_socket);
void			display_prompt(void);
int 			first_msg(char *buff);
int 			check_list_member(char *buff);
void			cut_list(char *list, t_ncurse *curs);
// void			action(int client_socket, t_info_client *client);
void			action(int client_socket, t_info_client *client, struct sockaddr_in server_info, struct hostent *host_server);

// void			connect_server(int cli_sock, struct sockaddr_in serv_inf, t_info_client *client);
void	connect_server(int cli_sock, struct sockaddr_in serv_inf, t_info_client *client, struct hostent *host_server);


void			check_input_client(int ac);
char			*trim_input(char *str);
void			update_nickname(char *name, int client_socket);
void			env_server(char *buff, int client_socket);
int 			send_mess(int y, int client_socket, t_ncurse *curs, t_info_client *client);
void			exec_cmd_client(char *buff, t_info_client *client, t_ncurse *curs);
void			updt_nickname(char *buff, t_info_client *client);

int 			check_channel(char *channel);
void			join_channel(char *channel, int client_socket, t_lst_member *member);
void			exit_channel(int client_socket, char *buff, t_lst_member * member);

void			exec_cmd_sev(char *buff, int client_socket, t_lst_member *member);
void			send_member_lst(int client, t_lst_member *member);
char			*get_list_member(t_lst_member *member);
void			upd_nick(char *name, int client_socket, t_lst_member *member);
void			send_private_msg(int client_socket, char *buff, t_lst_member *member);

void			ft_error_i(char *msg, int i);
void			ft_error(char *msg);

int 			empty_list(t_lst_member *list);
void			ft_display_member(t_lst_member *list);
void			ft_add_member(t_lst_member *list, char *nickname, char *chanel, int socket);
t_lst_member	*creat_new_list(t_lst_member *membre, t_irc *irc);
int				ft_size_socket(t_lst_member *list);

t_ncurse		*init_curses(void);
void			end_curses(t_ncurse *curs);
void			draw_irc(t_ncurse *curs);

char			*get_user_name(char **env);
void			check_input_server(int ac);
int 			get_max_socket(int sock, int sockmax);
int 			ft_strlen_tab(int *tab);

int				create_socket(int server_socket);
int				init_server(int server_socket, struct sockaddr_in server_addr);
int				wait_connect(int s_sock, int c_s, struct sockaddr_in c_adr);
char			*custom_buffer(char buff[1024], int sender, t_lst_member *member);

#endif