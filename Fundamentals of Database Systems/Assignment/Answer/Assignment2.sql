use xsj;

# Question1
select  model
from PC
where speed >= 3.00;

# Question2

select distinct maker
from laptop natural join product
where hd >= 512;

# Question3
select model, price from laptop natural join product where maker="B" union
select model, price from PC natural join product where maker="B" union
select model, price from product natural join printer where maker="B" ;

# Question4
select model 
from printer 
where color=1 and  `type` ="laser";

# Question5
select distinct maker 
from laptop natural join product 
where maker not in (select maker from PC join product);

# Question6
select distinct d.hd
from PC as t, PC as d
where t.model != d.model and d.hd = t.hd; 

# Question7
select d.model, t.model
from PC as t, PC as d
where d.speed = t.speed and d.ram = t.ram and d.model > t.model;

# Question8
select distinct maker from pc join product where speed>=2.8
group by maker
having count(speed)>1
union
select distinct maker from laptop join product where speed>=2.8
group by maker
having count(speed)>1;

# Question9
select distinct maker
from pc natural join product 
where speed=(select max(speed) from pc join product)
union 
select distinct maker
from laptop natural join product 
where speed=(select max(speed) from laptop join product);

# Question10
select distinct maker
from pc natural join product 
group by maker
having count(distinct speed) > 2;

# Question11
select distinct maker
from pc natural join product 
group by maker
having count(model) = 3;



