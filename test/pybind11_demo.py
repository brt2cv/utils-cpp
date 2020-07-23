import json

def get_json_value(path_json, key: str):
    """ return the value of json-key """
    with open(path_json, "r") as fp:
        dict_json = json.load(fp)
        value = dict_json.get(key, None)
    return value if value else "Null..."

def get_json_value_recursed(path_json, list_keys: list):
    """ return the value of json-key """
    with open(path_json, "r") as fp:
        dict_json = json.load(fp)
        for key in list_keys:
            dict_json = dict_json.get(key, None)
            if not dict_json:
                return "Null..."
    return dict_json

def get_demo_value():
    return get_json_value_recursed("test/json_demo.json", ["hello", "hi"])

if __name__ == "__main__":
    print(get_demo_value())
