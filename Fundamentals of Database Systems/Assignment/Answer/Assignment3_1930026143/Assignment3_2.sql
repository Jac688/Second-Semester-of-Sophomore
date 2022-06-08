use realtor;

DROP TABLE if EXISTS `sale`;
DROP TABLE if EXISTS `work_on`;
DROP TABLE if EXISTS `transfer`;
DROP TABLE if EXISTS `agency`;
DROP TABLE if EXISTS `agent`;
DROP TABLE if EXISTS `property`;


create table `agent` (
    `at_name` char(30) not null, 
    `employment`  char(30) not null,
    `at_phone` char(20) not null,
    primary key (`at_name`)
) engine=InnoDB default charset=utf8mb4;

create table `agency` (
    `acy_name` char(30) not null, 
    `acy_address`  char(100) not null,
    `acy_phone` char(20) not null,
    primary key (`acy_name`)
) engine=InnoDB default charset=utf8mb4;


create table `work_on` (
    `at_name` char(30) not null unique, 
    `acy_name`  char(100) not null,
    foreign key (`at_name`) references `agent`(`at_name`) 
    on delete cascade on update cascade,
    foreign key (`acy_name`) references `agency`(`acy_name`) 
    on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;

create table `property` (
	`list_#` int not null, 
    `list_date` date not null,
    `sale_price` float not null,
    `list_address` char(100) not null,
    `seller_name` char(30) not null,
    `type` char(20) not null,
    `cnt_bedroom` int not null,
    `cnt_bathroom` int not null,
    `cnt_floor` int not null,
    `footage` float not null,
    `age` int not null,
    `car_fit` int not null,
    primary key (`list_#`)
) engine=InnoDB default charset=utf8mb4;

create table `sale` (
	`list_#` int not null,
    `acy_name` char(100) not null unique,
    `at_name` char(30) not null unique,
    foreign key (`list_#`) references `property`(`list_#`)
    on delete cascade on update cascade,
    foreign key (`acy_name`) references `agency`(`acy_name`) 
    on delete cascade on update cascade,
    foreign key (`at_name`) references `agent`(`at_name`) 
    on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;



CREATE TABLE `transfer` (
    `list_#` INT NOT NULL,
    `tran_date` DATE NOT NULL,
    `buyer_name` CHAR(30) NOT NULL,
    `acy_name` CHAR(30) NOT NULL,
    `at_name` CHAR(30) NOT NULL,
    `tran_price` float not null,
    foreign key (`list_#`) references `property`(`list_#`)
    on delete cascade on update cascade,
    foreign key (`acy_name`) references `agency`(`acy_name`) 
    on delete cascade on update cascade,
    foreign key (`at_name`) references `agent`(`at_name`) 
    on delete cascade on update cascade
) ENGINE=INNODB DEFAULT CHARSET=UTF8MB4;