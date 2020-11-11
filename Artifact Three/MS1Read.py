import json
import pprint
from bson import json_util
from pymongo import MongoClient

connection = MongoClient('localhost', 27017)
db = connection['city']
collection = db['inspections']

def read_document(document):
  try:
    inspections_data = collection.find_one({"id" : "25612-2020-ARMY"})
    pprint.pprint(inspections_data)
    
    if inspections_data == None:
        print('False')
    else:
        print('True')
    
  except ValidationError as ve:
    abort(400, str(ve))
    return result
    
def main():
    myDocument = {"keyName": "test value data"}
    
    
    print read_document(myDocument)
    
main()