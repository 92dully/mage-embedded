# Markdown Syntax Reference

## Headings

Use `#` for headings. The number of `#` symbols determines the level of the heading.

```markdown
# H1 - Main Heading
## H2 - Subheading
### H3 - Third Level Heading
#### H4 - Fourth Level Heading
##### H5 - Fifth Level Heading
###### H6 - Sixth Level Heading
```

## Text Styling

### Bold
```markdown
**Bold Text** or __Bold Text__
```

### Italic
```markdown
*Italic Text* or _Italic Text_
```

### Strikethrough
```markdown
~~Strikethrough Text~~
```

### Code (Inline)
```markdown
`Inline code`
```

### Code (Block)
Use triple backticks for code blocks. You can specify the language for syntax highlighting.

```markdown
```python
def hello_world():
    print("Hello, world!")
```
```

## Lists

### Unordered List
```markdown
- Item 1
- Item 2
  - Subitem 1
  - Subitem 2
- Item 3
```

### Ordered List
```markdown
1. First item
2. Second item
3. Third item
```

### Task Lists (Checkboxes)
```markdown
- [ ] Task 1
- [x] Task 2 (Completed)
```

## Links

### Simple Link
```markdown
[Link Text](https://example.com)
```

### Link with Title
```markdown
[Link Text](https://example.com "Optional Title Here")
```

## Images

```markdown
![Alt Text](image-url.jpg)
```

You can also add titles to images:
```markdown
![Alt Text](image-url.jpg "Image Title")
```

## Blockquotes
```markdown
> This is a blockquote.
> 
> It can span multiple lines.
```

## Horizontal Line
```markdown
---
```
or
```markdown
***
```
or
```markdown
___
```

## Tables

```markdown
| Header 1 | Header 2 | Header 3 |
|----------|----------|----------|
| Row 1, Col 1 | Row 1, Col 2 | Row 1, Col 3 |
| Row 2, Col 1 | Row 2, Col 2 | Row 2, Col 3 |
```

## Links to Sections (Anchors)

You can link to sections within your document by using the header text, but with hyphens instead of spaces and all lowercase.

```markdown
[Link to Section](#section-heading)
```

Example:
```markdown
## Example Section
```
Linking to it:
```markdown
[Go to Example Section](#example-section)
```

## Inline HTML

You can also embed raw HTML if you need more control (e.g., for styling).

```markdown
<p>This is a custom paragraph using HTML.</p>
```

## Escaping Special Characters

If you need to display Markdown syntax as plain text, escape the special characters with a backslash (`\`).

Example:
```markdown
\*This text is not italicized\*
```

This will display as:
```
*This text is not italicized*
```

---

## Miscellaneous

### Footnotes

```markdown
Here is a sentence with a footnote[^1].

[^1]: This is the footnote.
```

### Inline HTML

For complex formatting or styles not supported by Markdown, you can use HTML:

```markdown
<p>This is a paragraph written using HTML.</p>
```

### Emoji

You can use emojis by typing the corresponding code inside colons:

```markdown
:smile: :thumbsup: :rocket:
```

### Links to External Files
You can link to external files like PDFs, images, etc.:

```markdown
[Download PDF](file.pdf)
```

---
