import csv
import json
from banner import banner
from concurrent.futures import ThreadPoolExecutor

def arranger(endNum):
    csvFile = input('before.csv: ')
    jsonFile = 'after.json'
    flag = 0
    data = []
    with open(csvFile) as csv_obj:
        csvReader = csv.DictReader(csv_obj)
        for row in csvReader:
            if flag == endNum:
                break
            else:
                data.append(row)
                flag += 1
            with open(jsonFile, 'w') as json_obj:
                new = json.dumps(data, separators=(',', ': '), indent=4)
                json_obj.write(new)
    return "Finish"


def main():
    banner()
    executor = ThreadPoolExecutor(10)
    future = executor.submit(arranger, (13005))
    print(future.result())

if __name__ == '__main__':
    main()
