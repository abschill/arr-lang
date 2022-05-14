~~ to add comments, use the tilde and it will be ignored by the compiler

~~ we need $ because we are evaluating the collection of collections
foods$=(['peanuts', 'cashews'], ['apples', 'grapes'])

~~ the i directive indexes the collection to the name submitted
~~ if the i directive is specified, it means that 'nuts' is assigned to peanuts&cashews as a food group.
food_groups$=i(foods):('nuts', 'fruits')

~~the line being down here instead of above would still work the same bc of the way the syntax will ultimately be hoisted when compiled.
~~foods$=(['peanuts', 'cashews'], ['apples', 'grapes'])
