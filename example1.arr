~~ to add comments, use the tilde and it will be ignored by the compiler

foods=(['peanuts', 'cashews'], ['apples', 'grapes'])

~~ the i directive indexes the collection to the name submitted
~~ if the i directive is specified, it means that 'nuts' is assigned to peanuts&cashews as a food group. 
food_groups=i(foods):('nuts', 'fruits')