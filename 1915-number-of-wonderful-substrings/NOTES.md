ques wants ki saare even substring chalenge aur sirf odd ho mtlb sirf ek character toh woh bhi chalega;


step1: a ko binary mei nikalo ,a=001; b=010,c=100,d=1000,
                                                 shift karke1<<ch-'a'
 
 step 2:  humme janna hai ki sirf even contain karne wale substring kitne hai
            a^a=0
						a^a^a=a;
	exp: aabb
	  a
		s1:ki yeh  substring even hai ki  odd 
		toh pehle kabhi 001 dekha hai kya map mei nhi toh phir yeh even nhi
		s2:001^000 =001 dekha hai map mei mtlb sirf ek odd hai toh chalega ans mei add kar dena
		
		aa
		001^001 =000 
		map mei dekha hai  jitne baar usse ans mei add kr dena 
		yeh even  ka check ho gya mtlb aa valid hai 
		
		
		phir  odd ka check krna hoga 
		000^001 =001 map mei toh jitne baar hai woh add kar dena 
		
		
		aur baar baar map mei insert karte rehna ​
