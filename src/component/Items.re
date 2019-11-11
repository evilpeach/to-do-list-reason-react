module Styles = {
  open Css;

  let listcontainer =
    style([display(`flex), flexDirection(`column), alignItems(`center)]);

  let listbox = style([flexDirection(`row), position(`relative)]);

  let list = completed =>
    style([
      marginTop(`px(10)),
      marginBottom(`px(10)),
      backgroundColor(Css_Colors.white),
      fontSize(`px(16)),
      textDecoration(completed ? `lineThrough : `none),
      cursor(`pointer),
    ]);

  let closebtn =
    style([
      cursor(`pointer),
      position(`absolute),
      right(`px(-70)),
      top(`px(10)),
    ]);
};

type todo = {
  id: string,
  title: string,
  completed: bool,
};

type todos = list(todo);

[@react.component]
let make = (~todos, ~markDone, ~remove) => {
  <div className=Styles.listcontainer>
    {Helper.map(todos, todo =>
       <div className=Styles.listbox>
         <div
           key={todo.id}
           className={Styles.list(todo.completed)}
           onClick={_ => markDone(todo.id)}>
           {todo.title |> React.string}
         </div>
         <div className=Styles.closebtn onClick={_ => remove(todo.id)}>
           {"x" |> React.string}
         </div>
       </div>
     )
     |> Belt_List.toArray
     |> React.array}
  </div>;
};
