from json2html import *
import json

jsonFile = ''
htmlFile = ''

jsonFile = input("Enter Json File:")
htmlFile = input("Enter HTML Output File Name:")

with open(jsonFile, 'r', encoding="utf8") as jf_obj:
    lines = json.load(jf_obj)
    with open(htmlFile, 'a', encoding="utf8") as hf_obj:
        hf_obj.write(json2html.convert(json = lines))

