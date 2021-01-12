drop database if exists epytodo;
create database  if not EXISTS epytodo ;
use epytodo;

create table user(username varchar(25) not null);
create table task(task_id int not null, title varchar(25) not null, status int, PRIMARY KEY (task_id));
create table user_has_task(fk_user_id int not null, fk_task_id int not null, PRIMARY KEY (fk_task_id));
create user if not EXISTS 'user'@'localhost' IDENTIFIED by 'password';
grant ALL PRIVILEGES on * to 'user'@'localhost';