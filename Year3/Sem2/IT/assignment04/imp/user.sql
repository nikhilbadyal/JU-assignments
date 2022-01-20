create table user
(
    fname    varchar(255) null,
    lname    varchar(255) null,
    email    varchar(255) null,
    password varchar(255) null,
    gender   varchar(255) null,
    prefer   varchar(255) null
);

INSERT INTO app_store.user (fname, lname, email, password, gender, prefer) VALUES ('nikhil', 'badyal', 'nikhil@nikhil', 'nikhil', 'men', 'discounts');
INSERT INTO app_store.user (fname, lname, email, password, gender, prefer) VALUES ('aikhil', 'badyal', 'aikhil@aikhil', 'aikhil', 'men', 'discount');
INSERT INTO app_store.user (fname, lname, email, password, gender, prefer) VALUES ('aman', 'sharma', 'aman@aman', 'aman', 'women', 'new');