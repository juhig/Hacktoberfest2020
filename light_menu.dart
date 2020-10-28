ListView buildListView(BuildContext context) {
  return ListView(children: <Widget>[
    new UserAccountsDrawerHeader(
        accountName: null,
        accountEmail: null,
        decoration: BoxDecoration(
          color: Colors.blue,
        )),
    new ListTile(
        leading: Icon(Icons.web),
        title: new Text('name'),
        onTap: () {
          Navigator.of(context).pop();
          Navigator.push(
              context,
              new MaterialPageRoute(
                  builder: (BuildContext context) => new name()));
        }),
