def hi( data ):
    count_dict = {}
    price_dict = {}

    row_data = data.split('\n')
    for row in row_data:
        txn = row.split(',')
        