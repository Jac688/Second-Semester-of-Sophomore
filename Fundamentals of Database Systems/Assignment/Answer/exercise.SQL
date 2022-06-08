select ename, salary
from Employee
where emp_id in 
(select emp_id
from Project natural join Work_on
where pname = '231Project');

select distinct d.ename 
from Employee as d
where not exists
((select pid from Project where dept_no=5) except (select pid from Work_on as t where t.emp_id = d.emp_id));


select pid, pname, count(emp_id)
from Work_on natural join Employee
group by pid
having count(emp_id) >= 2;

# 2
with boston_person(person_name) as
select person_name
from works natural join company
where city = 'Boston'
select distinct street
from employee natural join boston_person;

select street
from works natural join company
where  city = 'Boston'
group by person_name
having count(city) = 1;

select person_name
from employee natural join works
where  city = 'Hong Kong'
group by person_name
having sum(salary) > 10000;

select distinct person_name 
from employee 
where person_name in 
(select manager_name
from manages);

select distinct person_name
from employee natural join company
where company_name = 'First Bnak Corporation';

select person_name, city
from employee 
where person_name in 
(select person_name
from works natural join company
group by person_name
having count(company_name)=1);

select person_name
from works
where salary > some(select salary from works where company_name = 'Small Bank Corporation');

select company_name 
from company 
where city = 'Hong Kong' and company_name in
(select company_name, max(count(person_name))
from works
group by company_name
having count(person_name));

select company_name 
from company 
where city = 'Hong Kong' and company_name in
(select company_name
from works 
group by company_name
having sum(salary)<100000);

select person_name 
from works
group by person_name
having sum(salary) > all(select d.sum(salary)
from employee natural works as d
where city = 'Los Angeles'
group by person_name);

select distinct m1.manager_name
from manages as d, works as t
where d.person_name = t.manager_name
group by manager_name 
having sum(salary) > some 
(select sum(salary) 
from works as w, manages as m 
where w.person_name = m.person_name 
and d.manager_name = m.manager_name 
group by w2.person_name);

# 3
select distinct cname 
from CUST as c, WITHDRAW as w 
where c.cust-id = w.cust-id and w.amount > 1000;

select distinct acc_id
from WITHDRAW
group by acc-id
having count(distinct cust-id) >= 2;

select cust-id 
from WITHDRAW 
where acc-id = 'A1' or acc-id = 'A2'
group by cust-id
having count(distinct acc-id) = 1;

select cust-id 
from WITHDRAW 
group by cust-id
having count(cust-id) >= all
(select count(cust-id) 
from WITHDRAW
group by cust-id);

select distinct acc_id
from WITHDRAW
where acc-id not in
(select distinct acc_id
from WITHDRAW as interesting_account
where amount = (select min(amount) from WITHDRAW));

select prof-id, name, stu-id
from CS_PROF left outer join SUPERVISION
on CS-PROF.prof-id = SUPERVISION.prof-id;

select *
from CS_PROF left outer join SUPERVISION
on CS-PROF.prof-id = SUPERVISION.prof-id;

select *
from CS_PROF natural join SUPERVISION
where CS-PROF.id = SUPERVISION.id
union 
select *
from CS_PROF
where not exists
(select * 
from SUPERVISION
where CS_PROF.prof-id = SUPERVISION.prof-id);

select stu-id 
from MARKS
where score < 90
except
select stu-id 
from MARKS
where score < 80;

select stu-id
from MARKS
where score < 90 and score >= 80;























