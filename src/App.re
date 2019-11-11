module Styles = {
  open Css;

  let container =
    style([
      width(`percent(100.)),
      height(`percent(100.)),
      position(`relative),
      display(`flex),
      flexDirection(`column),
      alignItems(`center),
    ]);

  let header =
    style([
      fontSize(`px(48)),
      marginTop(`px(30)),
      marginBottom(`px(15)),
    ]);
};

[@react.component]
let make = () => {
  let (todos, setTodos) = React.useState(_ => []);

  let add = title => {
    let x = String.trim(title);
    let uuidv4 = Uuid.V4.uuidv4();

    if (x != "") {
      let todo: Items.todo = {id: uuidv4, title: x, completed: false};
      setTodos(_ => Helper.pushback(todo, todos));
    } else {
      ();
    };
  };

  let markDone = (id: string) => {
    let newTodos =
      Helper.map(todos, todo =>
        {
          Items.id: todo.id,
          title: todo.title,
          completed:
            if (todo.completed) {
              if (todo.id == id) {
                false;
              } else {
                true;
              };
            } else if (todo.id == id) {
              true;
            } else {
              false;
            },
        }
      );
    setTodos(_ => newTodos);
  };

  let remove = (id: string) => {
    let filtered =
      Helper.filter((x: Items.todo) => x.id != id ? true : false, todos);
    setTodos(_ => filtered);
  };

  <div className=Styles.container>
    <div className=Styles.header> {"To do list" |> React.string} </div>
    <Form onSubmit={value => add(value)} />
    <Items todos markDone remove />
  </div>;
};
