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