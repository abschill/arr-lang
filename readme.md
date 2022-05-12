# arrlang

## Use Case

create collection-based data structures with baked in relationship support


### Basic syntax

```html
<collection_name>=(<collection_expression>)
```


### Configuration

if you would like to customize the discretions for the processor to take in generating your json/xml/sql you can create a file named `.arrlangc` with key/value pairs for config options

the options are as follows


- output
    - `xml`
    - `json`
    - `sql`
- error
    - `all`
    - `strict`
    - `lax`
    - `silent`


example `.arrlangc`

```txt
output=xml
error=all
```


### Example usage

Say you want to generate a shopping list categorized by the types of foods you want to buy. Let's say you wanted to buy some fruit, some grains, and some vegtables. We will organize our list in this example

### Step 1: Define the grocery list global

```arr
grocery_list$=()
```

We use the `$` operator to tell the compiler we're declaring a new variable which can be reassigned. to assign a variable as constant or reassign, you may omit `$` from the above syntax. 


### Step 2: Define food groups

```arr
food_groups$=('fruit', 'grains', 'vegtables')
```

This gives us a 1d array of strings which we can apply in whatever data structures we want in our file.

This syntax above is essentially the same as doing this:

```arr
food_groups=(['fruit', 'grains', 'vegtables'])
```
You'll notice that if you are using the array as a static value, it will not require a $ because the expression is already in list format and will not need to be transposed during parsing.

What () is essentially doing is evaluating an expression, and [] is interpreted as a static group of collection items. So when the parser sees that there is nothing to evaluate, it just performs a no-op and continues along. 


### Step 3: index the food groups to the grocery_list

```arr
grocery_list$=()
food_groups=i(grocery_list)(['fruit', 'grains', 'vegtables'])
```

What we do here is use the `i` directive, short for `index` and what this does is say "the first item in the grocery_list collection is a list of fruits, second is grains, third is vegtables". At the moment we have nothing in our grocery list, so nothing is indexed, but it will automatically cascade for us if we add items into it. In other words, we can set up each index to be a list itself, keyed by the `i` directive. 


### Step 4: insert static or dynamic data to the list

```arr
grocery_list=(['apples', 'bananas'], ['bread'], ['brussels-sprouts', 'corn'])
food_groups=i(grocery_list)(['fruit', 'grains', 'vegtables'])
```

so now this could be rendered into JSON as 

```json
{
    "grocery_list": {
        "food_groups": {
            "fruit": ["apples", "bananas"],
            "grains": ["bread"],
            "vegtables": ["brussels-sprouts", "corn"]
        }
    }
}
```