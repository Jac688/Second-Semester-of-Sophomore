use `job`;

DROP TABLE if EXISTS `isProfficientIn`;
DROP TABLE if EXISTS `Uses`;
DROP TABLE if EXISTS `WorkOn`;
DROP TABLE if EXISTS `Order`;
DROP TABLE if EXISTS `Client`;
DROP TABLE if EXISTS `Employee`;
DROP TABLE if EXISTS `Project`;
DROP TABLE if EXISTS `Technologies`;


create table `Client`(
	`company_name` varchar (30) not null,
	`adress` varchar(100) not null,
	`phone` varchar(20) not null,
	`email` varchar(20) not null,
	`fax` varchar(20) not null,
	`linkman` varchar(20) not null,
	primary key (`company_name`)
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `Project`(
	`code_name` varchar(20) not null,
	`in_date` date not null ,
	`com_date` date not null,
	`budget` float not null,
    primary key (`code_name`)
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `Employee`(
	`e_ID` varchar(20) not null,
	`e_name` varchar(20) not null,
	`hire_date` date not null,
	`position` varchar(20) not null,
	`salary` float not null,
    primary key (`e_ID`)
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `Technologies`(
	`tech_name` varchar(20) not null,
	`fir_date` date not null,
	`used_cnt` integer not null,
	primary key (`tech_name`)
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `Uses`(
	`code_name` varchar(20) not null,
	`tech_name` varchar(20) not null,
	-- primary key (`code_name`, `tech_name`),
	foreign key(`code_name`) references `Project`(`code_name`) on delete cascade on update cascade,
	foreign key(`tech_name`) references `Technologies`(`tech_name`) on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `WorkOn`(
	`e_ID` varchar(20) not null,
	`code_name` varchar(20) not null,
	`precent` float not null,
	-- primary key(`e_ID`, `code_name`),
	foreign key(`e_ID`) references `Employee`(`e_ID`) on delete cascade on update cascade,
	foreign key(`code_name`) references `Project`(`code_name`) on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `Order`(
	`company_name` varchar(30) not null unique,
	`code_name` varchar(20) not null unique,
	-- primary key (`company_name`, `code_name`),
	foreign key (`company_name`) references `Client`(`company_name`) on delete cascade on update cascade,
	foreign key (`code_name`) references `Project`(`code_name`) on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;

CREATE TABLE `isProfficientIn`(
	`e_ID` varchar(20) not null,
	`tech_name` varchar(20) not null,
	-- primary key (`e_id`, `tech_name`),
	foreign key (`e_id`) references Employee(`e_id`) on delete cascade on update cascade,
	foreign key (`tech_name`) references `Technologies`(`tech_name`) on delete cascade on update cascade
) engine=InnoDB default charset=utf8mb4;