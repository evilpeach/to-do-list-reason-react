module Styles = {
  open Css;

  let form =
    style([
      width(`percent(30.0)),
      height(`px(40)),
      marginTop(`px(15)),
      marginBottom(`px(15)),
    ]);

  let input =
    style([
      width(`percent(100.)),
      height(`percent(100.)),
      position(`relative),
      border(`px(1), `solid, Css_Colors.antiquewhite),
      borderRadius(`px(4)),
      paddingLeft(`px(10)),
      fontSize(`px(16)),
    ]);
};

[@react.component]
let make = (~onSubmit) => {
  let (value, onChange) = React.useState(_ => "");

  <form
    className=Styles.form
    onSubmit={event => {
      ReactEvent.Synthetic.preventDefault(event);
      onSubmit(value);
      onChange(_ => "");
    }}>
    <input
      className=Styles.input
      value
      placeholder="remember this"
      onChange={event => onChange(ReactEvent.Form.target(event)##value)}
    />
  </form>;
};
