var book = {
    title: "Professional Javascript",
    authors: [
        "Nicholas C. Zakas"
    ],
    edition: 3,
    year: 2011
};
var jsonText = JOSN.stringify(book);
console.log(jsonText);